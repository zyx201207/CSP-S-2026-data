#include<bits/stdc++.h> 
using namespace std;
long long n,a[200005],t,s;
	char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i]>>c[i];t=t+a[i];
	}
	long long d=1,e=n;
	long long h1=a[d],u1=1,u2=1,h2=a[e];;
	char m1=c[d],m2=c[e];
for(long long j=1;j<=t/2;j++ ){
	long long q1=min(h1-u1+1,t-j),q2=min(h2-u2+1,t-j);j=j+min(q1,q2)-1;if(m1!=m2)s=s+min(q1,q2);if(q1>q2){e--;h2=a[e];m2=c[e];u2=1;u1=u1+q2;
	}else if(q1<q2){d++;h1=a[d];m1=c[d];u1=1;u2=u2+q1;
	}else {d++;e--;h1=a[d];m1=c[d];u1=1;h2=a[e];m2=c[e];u2=1;
	}
	

}cout<<s;
	return 0;
}
