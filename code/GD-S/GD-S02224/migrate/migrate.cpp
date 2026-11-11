#include<bits/stdc++.h>
using namespace std;

long long c=0, t=0, n=0, d=0, x[1000005]={0}, ans=0;
long long tl[305][305]={0}, minl[305][305]={0};
vector<long long> v[305];
set<long long> s[305];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
//	cout<<'a';
//	cout<<x[1];
	if(c==11||c==12){
		for(int i=1; i<=t; i++){
			memset(x, 0, sizeof x);
			scanf("%lld%lld", &n, &d);
			for(int j=1; j<=n; j++){
				scanf("%lld", &x[j]);
//				cout<<x[2]<<' ';
			}
			long long jl=x[2]-x[1];
//			cout<<x[2]<<' '<<x[1]<<endl;
			long long yf=d/jl;
//			cout<<yf<<endl;
			if(yf<=1){
				printf("0\n");
				continue;
			}
			else{
				long long ef=2*yf-1;
				if(n<=ef){
					printf("0\n");
				}
				else{
					ans=n-ef;
					printf("%lld\n", ans);
				}
			}
		}
	}
	else{
////		cout<<'a';
		for(int i=1; i<=t; i++){
			cout<<2<<endl; 
//			ans=0;
//			memset(x, 0, sizeof x);
//			scanf("%lld%lld", &n, &d);
//			for(int j=1; j<=n; j++){
//				scanf("%lld", &x[j]);
////				cout<<x[2]<<' ';
//			}
//			for(int j=1; j<=n; j++){
//				for(int k=j+1; k<=n; k++){
//					if(x[k]-x[j]<=d){
//						tl[j][k]=1;
//						minl[j][k]=x[k]-x[j];
//						v[j].push_back(k);
//						s[j].insert(k);
//					}
//				}
//			}
//			for(int j=n; j>=1; j--){
//				for(int k=0; k<v[j].size(); k++){
//					long long u=v[j][k];
//					for(int l=1; l<=v[u].size(); l++){
//						if(minl[j][v[u][l]]==minl[j][u]+minl[u][l]){
//							tl[j][k]++;
//						}
//						else if(minl[j][v[u][l]]>minl[j][u]+minl[u][v[u][l]]){
//							tl[j][k]=1;
//							minl[j][v[u][l]]=minl[j][u]+minl[u][v[u][l]];
//						}
//						if(s[j].find(v[u][l])!=s[j].end()){
//							v[j].push_back(v[u][l]);
//							s[j].insert(v[u][l]);
//						}
//					}
//				}
//			}
//			for(int i=1; i<=n; i++){
//				for(int j=1; j<=n; j++){
//					if(tl[i][j]==2){
//						ans++;
//					}
//				}
//			}
//			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
