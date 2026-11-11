//GZ-J00423 兴义市弘毅中学 王富俊
#include<bits/stdc++.h>
using namespace std;

char a[200020],za[200020];
long long n,leng,zleng,l,op,f,zf,ts,ans,g,i;
long long h[200020],zh[200050];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	leng=0;
	for(i=1;i<=n;i++){
		cin>>h[i]>>a[i];
		leng=leng+h[i];
	}
	
	l=leng/2;
	if(leng%2==0){
		g=0;
	}
	else{
		g=1;
	}
	
	for(i=n;i>=1;i--){
		zh[n+1-i]=h[i];
		za[n+1-i]=a[i];
		zleng=zleng+h[i];
		ts++;
		if(zleng>=l){
			zh[n+1-i]=l-zleng+h[i];
			h[i]=h[i]-zh[n+1-i]-g;
			break;
		}
	}

	f=1;
	zf=1;
	i=0;
	
	while(i<l){
		if(h[f]>=zh[zf]){
			op=zh[zf];
			if(a[f]!=za[zf]){
				ans=ans+op;
			}
			zf++;
			h[f]=h[f]-op;
			if(h[f]==0){
				f++;
			}
		}
		else if(h[f]<zh[zf]){
			op=h[f];
			if(a[f]!=za[zf]){
				ans=ans+op;
			}
			f++;
			zh[zf]=zh[zf]-op;
		}
		i=i+op;
	}
	
	cout<<ans;
	
	return 0;
} 
 
