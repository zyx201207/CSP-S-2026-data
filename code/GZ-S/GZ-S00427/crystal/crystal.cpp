//GZ-S00427 卢泓宇 遵义市第一中学
#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int num=0;
	int b[n];
	for(int i=1,j=i+1;i<n;i++,j++){
		b[i]=a[j]-a[i];
		if(b[i]==0){
			num++;
		}
		}
	sort(b+1,b+n+1,cmp);
	int i=1;
	while(b[i]<=m){
		m-=b[i];
		num++;
		i++;
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
}

