#include <bits/stdc++.h>
using namespace std;
int a[500005];
int d[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool task=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]<a[i-1]) task=false;
	}
	if(task){
		for(int i=1;i<=n;i++){
			d[a[i]]++;
		}
		int sum=0;
		for(int i=1;i<=m;i++){
			sum+=d[i];
			cout<<sum<<" ";
		}
	}else{
		vector<int> cnt(m+5,0);
		vector<int> vec;
		for(int i=1;i<=n;i++){
			vec.clear();
			for(int j=i;j<=n;j++){
				vector<int> temp;
				for(int k=0;k<vec.size();k++){
					if(a[j]!=vec[k]) temp.push_back(vec[k]);
					else{
						vec=temp;
						break;
					}
				}
				vec.push_back(a[j]);
			}
			for(int i:vec) cnt[i]++;
		}
		for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
