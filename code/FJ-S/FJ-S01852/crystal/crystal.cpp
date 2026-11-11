#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500005],b[500005];
int ans=1;
//a is nomal,b is qianzhuihe
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	//scanf("%ll %ll",&n,&m);
	for(int i=1;i<=n;i++)cin>>a[i];
	//for(long long i=1;i<=n;i++)scanf("%ll",&a[i]);
	sort(a+1,a+n+1);
	
	//-----------------------------------------------//
    if(n>5000){
	long long Cyrene=a[2]-a[1];
    long long Phainon=1;
    while(Phainon*(Phainon-1)*Cyrene<=2*m){
    if(Phainon>=n){Phainon=n;break;}
    if(Phainon*(Phainon+1)*Cyrene>2*m)break;
    Phainon++;
	}
    cout<<Phainon;
    return 0;
	}
    //-----------------------------------------------//
    
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=2;i<=n;i++){
		for(int g=1;g<=i-1;g++){
			if((i-g)*a[i]-(b[i-1]-b[g-1])<=m)ans=max(ans,i-g+1);
		}
	}
	printf("%d",ans);
	return 0;
}