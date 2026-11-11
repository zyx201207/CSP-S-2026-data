#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0,mm;
	cin>>n>>m;mm=m;
	map<int,int> a;
	vector<int> js;
	for(int i=0;i<n;i++){
		int p;cin>>p;
		if(a[p]==0) js.push_back(p);
		a[p]++;
	}
	int many=min(n,m)-1;
	for(int i=n-1;i>=0;i--){if(a[i]>a[many]) many=i;}
	sort(js.begin(),js.end());
	int wei=0;
	for(wei=int(js.size())-1;wei>=0;wei--){if(js[wei]==js[many])break;}
	//~ wei++;
	//~ cout<<wei<<" ";
	for(int i=wei;i>=0;i--){
		if(m>=(js[wei]-js[i])) {
			for(int j=0;j<a[js[i]];j++){
				m-=(js[wei]-js[i]);
				ans++;
			}
		}
	}
	if(a[many]==1){
		ans=0;
		for(int mid=n-1;mid>0;mid--){
			long long s=0;m=mm;
			//~ if(n%2!=0) mid++;
			//~ cout<<js[mid]<<" ";
			for(int i=mid;i>=0;i--){
				if(m>=(js[mid]-js[i])) {
					m=m-(js[mid]-js[i]);
					s++;
					//~ cout<<js[i]<<" "<<m<<endl;
				}
			}
			ans=max(ans,s);
		}
	}
	cout<<ans;
	return 0;
}
