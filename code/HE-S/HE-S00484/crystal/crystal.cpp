#include<bits/stdc++.h>
using namespace std;
long long a[500002],b[500002],n,m,p=1,x=1,y,max1;//x:定位最前方宝石的坐标 max1:可用宝石的最大值
 

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==0){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int y=m;
		m=m-p*(a[i]-a[i-1]);
		if(m>=0){
			
			p++;
			max1=max(p,max1);
			
		}else{
			int gg=0;
			while(m<0){
				gg++;
				x++;
			m+=a[i]-a[x-1];
			}
			p=p-gg+1;	
				max1=max(p,max1);
		} 
	}
	cout<<max1;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
