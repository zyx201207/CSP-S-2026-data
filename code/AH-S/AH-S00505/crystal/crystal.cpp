#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum=0,xb=0,maxx1=1,maxx2=1,zh=0;
double p2=0;
double n2=0,minn=10000000000000;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
cin>>n>>m;
sum=m;
n2=n;
for(long long i=0;i<n;i++){
	cin>>a[i];
}
sort(a,a+n);
for(long long i=0;i<n;i++){
	zh=zh+a[i];
}
p2=zh/n2;
for(long long i=0;i<n;i++){
if(a[i]<p2){
	if(minn>p2-a[i]){
		minn=p2-a[i];
		xb=i;
	}
}else if(a[i]>p2){
	if(minn>a[i]-p2){
		minn=a[i]-p2;
		xb=i;
	}
}else{
		xb=1;
		break;
	}
}


for(long long j=xb;j>0;j--){
	if(a[xb]-a[j-1]<=sum){
		sum=sum-(a[xb]-a[j-1]);
		maxx1++;
	}
	else{
		break;
	}

}
for(long long j=xb;j<n-1;j++){
	if(a[j+1]-a[xb]<=sum){
		sum=sum-(a[j+1]-a[xb]);
		maxx1++;
	}else{
		break;
	}
}
sum=m;
for(long long j=xb;j<n-1;j++){
	if(a[j+1]-a[xb]<=sum){
		sum=sum-(a[j+1]-a[xb]);
		maxx2++;
	}else{
		break;
	}
	
}
for(long long j=xb;j>0;j--){
	if(a[xb]-a[j-1]<=sum){
		sum=sum-(a[xb]-a[j-1]);
		maxx2++;
	}
	else{
		break;
	}

}
if(maxx1>maxx2){
	cout<<maxx1;
}else{
	cout<<maxx2;
}
fclose(stdin);
fclose(stdout);
return 0;
}
