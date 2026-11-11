#include<bits/stdc++.h>
using namespace std;
//用暴力解掉1到5或9，和13到18的特判
//优先排序,然后取最大最小值，从最小值往上枚举并用桶优化 
//若是等差数列，直接套公式即可 
long long m,ma,mi,ma2=-1,a[500010],d[200010],c,ans,p,l;
int n,o;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
cin>>a[1];
mi=a[1];
ma=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i!=2)o=1;
			mi=min(mi,a[i]);
			ma=max(ma,a[i]);
	}
if(o==1){
	//不是等差的判定（桶） 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
    d[a[i]+100000]++;
	}
	mi+=100000;
	ma+=100000;
	for(int i=mi;i<=ma;i++){
		ans=0;
		p=0,l=0;
		for(int j=i;j>=mi;j--){
			if(d[j]!=0){
				for(int y=1;y<=d[j];y++){
					if(ans+(i-j)<=m){
					ans+=(i-j);
					l++;	
					}
					else{
						p=1;
						break;
					}
				}
			}
			if(p==1)break;
		}
		ma2=max(l,ma2);
	}
	cout<<ma2;
}
else{
	//等差数列的特判（特殊点A和B） 
	c=abs(a[2]-a[1]);
	int e=1;
	for(int i=1;;i++){
	if(ans+(i*c)>m)break;
	ans+=(i*c);
	e++;
	if(e>n)break; 
	}
	if(e>=n)cout<<n;
	else cout<<e;
}
	return 0;
}
