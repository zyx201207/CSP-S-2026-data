#include<bits/stdc++.h>
using namespace std;
int n,b[200010],p,q;
char a[200010];
long long sum=0,ss=0,ln,rn,li,ri,ans=0,k=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		sum+=b[i];
	}
	for(int i=1;i<=n;i++){
		if(ss<sum/2&&ss+b[i]>=sum/2){
			p=i;
			q=sum/2-ss;
		}
		ss+=b[i];
	}
	ln=rn=p,li=ri=q;
	if(sum%2==0){
		ri++;
		if(ri>b[rn])ri=1,rn++;
	}
	else{
		ri+=2;
		if(ri>b[rn])ri-=b[rn],rn++;
	}
	while(ln>0&&rn<=n){
		if(li>b[rn]-ri+1){
			if(a[ln]!=a[rn])ans+=(b[rn]-ri+1);
			li-=(b[rn]-ri+1);
			ri=1;
			rn++;
		}
		else if(li<b[rn]-ri+1){
			if(a[ln]!=a[rn])ans+=(li);
			ri+=li;
			li=b[ln-1];
			ln--;
		}
		else{
			if(a[ln]!=a[rn])ans+=(li);
			li=b[ln-1];
			ri=1;
			ln--;
			rn++;
		}
		if(ln==0||rn==n+1)break;
	}
	cout<<ans<<endl;
    return 0;
}
