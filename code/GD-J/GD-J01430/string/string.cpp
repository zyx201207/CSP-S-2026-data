#include<bits/stdc++.h> 
using namespace std;
long long n,a[200005],s;
long long l=1,r,x=1,y,t1,t2;
char c[200005],c1,c2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		y+=a[i];
	}
	while(x<y){
		if(t1==0)t1=a[l],c1=c[l];
		if(t2==0)t2=a[r],c2=c[r];
		if(c1!=c2)s+=min(t1,t2);
		if(t1>=t2){
			y-=t2,x+=t2,t1-=t2;
			t2=0,r--;
			if(t1==0)l++;
		}
		else{
			x+=t1,y-=t1,t2-=t1;
			t1=0,l++;
		}
	}
	cout<<s;
	return 0;
}

