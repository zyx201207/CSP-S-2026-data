#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	long long ans=-1e5;
	long long n,m;
	cin>>n>>m;
	long long s[100010],w[100010];
	for(long long i=0;i<n;i++){
		cin>>s[i];	
	//	cout<<s[i]<<" ";
	}
//	cout<<endl;
	for(long long i=0;i<n;i++){
		w[0]=s[i];
//		cout<<w[0]<<endl;
		long long anss=w[0];
		for(long long j=1;j<m;j++){
			for(long long k=i+1;k<n;k++){
				w[j]=s[k];
			}
			for(long long e=0;e<m;e++){
//					cout<<w[e]<<" ";
					anss=anss&w[e];
				}
//			cout<<endl;
			ans=max(ans,anss);
		}
	}
	cout<<ans;
	return 0;
} 
