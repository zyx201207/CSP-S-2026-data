#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct v{
	int a;
	char c;
}p[200030],m[200030];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll l=0,f,sum=0;
	cin>>n;
	int n1=n;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].c;
		l+=p[i].a;
	}
	f=l/2;
	bool fla=false;
	for(int i=1;i<=n;i++){
	if(sum+p[i].a<f or fla==true){
		m[i].a+=p[i].a;
		m[i].c=p[i].c;
	}
	m[i].c=p[i].c;
		if(fla==false){
		
		if(sum+p[i].a>f and l%2==1 ){
			m[i].a=f-sum-1;
			m[i+1].a=p[i].a-(f-sum);
			m[i+1].c=p[i].c;
			i++; 
			n++;
			fla=true;
		}else if(sum+p[i].a>f and l%2==0 ){
			m[i].a=f-sum;
			m[i+1].a=p[i].a-(f-sum);
			m[i+1].c=p[i].c;
			i++;
			n++;
			fla=true;
		}
		if(sum+p[i].a==f and l%2==1){
			m[i].a=p[i].a;
			m[i+1].a=-1;
			fla=true;
		}else if(sum+p[i].a==f and l%2==0){
			m[i].a=p[i].a;
			fla=true;
		}
	}

	sum+=p[i].a;
	}

	ll ans=0;
	for(int i=n1/2 ,j=n1/2+1;i>=1;){
		if(m[i].c!=m[j].c){
			ans+=min(m[i].a,m[j].a);
			m[i].a-=min(m[i].a,m[j].a);
			m[j].a-=min(m[i].a,m[j].a);
		}else{
			m[i].a-=min(m[i].a,m[j].a);
			m[j].a-=min(m[i].a,m[j].a);
		}
		if(m[i].a<=0 ){
			i--;
		}
		if(m[j].a<=0){
			j++;
		}
	}
	cout<<ans;
}
