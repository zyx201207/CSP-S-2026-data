#include<bits/stdc++.h>
using namespace std;
int ic[300005];
int ans[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a1[n+5];
	for (long long i=1;i<=n;i++){
		cin>>a1[i];
	}
	if (m==1){
		cout<<n;
		return 0;
	}
	if (m==2){
		long long cntone=0,cnttwo=0;
		for(long long o=1;o<=n;o++){
			vector<int> a;
			a.push_back(0);
			for (int i=o;i<=n;i++){
				a.push_back(a1[i]);
			}
			a.push_back(0);
			a.push_back(0);
			a.push_back(0);
			long long alla=n-o+1;
			bool is_one=0,is_two=0;
			for(int i=1;i<=alla;i++){
				if (a[i]==1) is_one=1;
				if (a[i]==2) is_two=1;
			}
			if (is_one){
				cntone++;
			}
			if (is_two){
				cnttwo++;
			}
		}
		cout<<cntone<<" "<<cnttwo<<"\n";
		return 0;
	} 
	for(int o=1;o<=n;o++){
		vector<int> a;
		a.push_back(0);
		for (int i=o;i<=n;i++){
			a.push_back(a1[i]);
		}
		a.push_back(0);
		a.push_back(0);
		a.push_back(0);
		long long alla=n-o+1;
		vector<int> v;
		v.push_back(-1e9);
		long long l=0,r=0;
		for (int i=1;i<=n;i++) {
			v.push_back(a[i]);
			r++;
			for(int j=l;j<=r;j++){
				if (v[j]==a[i]){
					l=i;
					r=i-1;
				}
			}
		}
		r++;
		memset(ic,0,sizeof(ic));
		for (int i=l;i<=r;i++){
			ic[v[i]]++;
		}
		for(int i=1;i<=m;i++){
			ans[ic[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
} 
           
                     
                
