//GZ-S00314 贵阳市第三实验中学 王钦澄 
#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
long long n,k,d,mi1[2000000][2000000],mi2[2000000][2000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin >> c >> t;
	while(t--){
		int ans=0;
		cin >> n >> d;
		a=vector<long long> (n+5,0);
		cout << c <<  ' ' << t << " " << n << " " << d;
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		for(int i=1;i<n;i++){
			k=i;
			for(int j=i-1;j>=0;j--){
				if((a[i]-a[j])>d){
					if(k==i){
						break;
					}
					mi1[j][i]=mi1[j][k]+1;
					mi2[j][i]+=1;
					for(int l=k;l<i;l++){
						if(mi1[j][i]==mi1[j][l]+1){
							mi2[j][i]+=1;
						}
					}
					if(mi2[j][i]==2){
						ans++;
					}
				}
				mi1[j][i]=1;
				mi2[j][i]=1;
				k=j;
			}
		}
		cout << ans;
	}
	return 0;
}
