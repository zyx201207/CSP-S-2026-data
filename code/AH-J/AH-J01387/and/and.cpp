#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[2000010],h[2000010];
long long ss(long long x){
	long long s=x,n=0,t=0;
	while(s>0){
		t++;
		h[t]=s%2;
		s/=2;
	}
	for(int i=t;i>0;i--){
		n=n*10+h[i];
	}
	return n;
}
long long dg(long long x,long long y){
	long long sum=0,t=0;
	while(x>0&&y>0){
		if(x%10==1&&y%10==1)sum+=pow(2,t);
		x/=10;
		y/=10;
		t++;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=ss(a[i]);
		for(int i=0;i<=2000010;i++)h[i]=0;
	}
	long long sum=0,x,y;
	m--;
	while(m--){
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++){
			if(i!=j){
			if(sum<dg(a[i],a[j])){
				sum=dg(a[i],a[j]);
				x=i;
				y=j;
			    }
		    }   
        }
    }

    if(m>0){
    a[x]=ss(sum);
    a[y]=0;
    sum=0;
}
}
cout<<sum;
	return 0;
}
