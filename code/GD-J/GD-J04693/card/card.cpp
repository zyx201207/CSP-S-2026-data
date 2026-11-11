#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],k;
bool s[300005]={0},s4[3000005]={0};
int s1[300005],s3[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//ios::sycn_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool xx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		if(a[i]>a[i+1]){
			xx=1;
			break;
		}
	}
	if(xx==1){
		for(int i=1;i<=n;i++){
			k=1;
			for(int ss=1;ss<=n*m;ss++){
				s[ss]=0,s1[ss]=0,b[ss]=0;
			}
			for(int j=i;j<=n;j++){
				if(s[a[j]]==1){
					for(int s2=s1[a[j]];s2<=k;s2++){
						s[b[s2]]=0;
						b[s2]=0;
						s1[b[s2]]=0;
						k--;
					}
					s[a[j]]=1;
					s1[a[j]]=k;
					b[k]=a[j];
				}else{
					s[a[j]]=1;
					s1[a[j]]=k;
					b[k]=a[j];
				}
			}
			for(int x=1;x<=m;x++){
				if(s[x]==1){
					s3[x]++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<s3[i]<<" ";
		}
	}else{
		for(int i=1;i<=m;i++){
			cout<<1<<" ";
		}
	}
	return 0;
}
