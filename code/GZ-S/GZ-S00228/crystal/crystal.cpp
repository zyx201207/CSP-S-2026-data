//GZ-S00228 遵义市第十九中学 张锣址杨 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5],num=1;
	for(int i= 0;i < n;i++){
		cin>>a[i];
	} 
	sort(a,a+n);
	int xian=(a[0]+a[n-1])/2,biao=0,x=0;
	for(int i = n-1;i >=0;i--){
		if(a[i]<=xian){
			biao=a[i];
			x=i;
			if(i!=0){
				if(a[i]-xian>xian-a[i-1]){
					biao=a[i-1];
					x=i-1;
				}
			}
			break;
		}
	}
	while(m>0&&x>0){
		int q=biao-a[x-1];
		m-=q;
		num++;
		x--;
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
