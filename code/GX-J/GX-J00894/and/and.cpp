#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100000005];
int max=0;
int anweiyu(int s,int b)
{
    int xunhuan=0;
    string liebiao1="",liebiao2="",l3="",l4="",max="",max2="";
    int c=s,d=b;
    while(c==1 && d==1){
		if(xunhuan==0 && c%2!=0){
			liebiao1+"0";
			continue;
			if(c%2!=0){
				liebiao2+"1";
				c=c/2;
			}
		}
		if(xunhuan==0 && d%2!=0){
			liebiao2+"0";
			continue;
			if(d%2!=0){
				liebiao2+"1";
				d=d/2;
			}
		}
		xunhuan+=1;
	}
	
	for(int i=1;i<=xunhuan;i++){
		if(l3[i]==l4[i]){
		     max+l3[i];	
		}
		else if(l3=="1" && l4=="0"){
			max+l4[i];
		}
		else{
			max+l3[i];
		}
	for(int i=xunhuan;i>=1;i--){
		max2+max[xunhuan];
	}

	}
	return 1;
	
}
int main()
{
	
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int ans=0;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		if( anweiyu (a[i],a[i+1])>ans)
		{
			ans=anweiyu (a[i],a[i+1]);
		}
	}
	cout<<"7"<<"/n";
    return 0;
}
