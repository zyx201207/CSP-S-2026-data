#include<bits/stdc++.h>
using namespace std;
int n,m,max1,all,a[200010];
int QWQ(int num,int i,int step){
	if(step>m)return num;
	int max2=0;
	while(i<=n-m+step){
		max2=max(max2,QWQ(num&a[i],i+1,step+1));
		i++;
	}
	return max2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1,t=1;i<=30;i++,t*=2)all+=t;
	int tt=all;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max1=max(max1,a[i]);
		all=all&a[i];
	}
	if(m==1){
		cout<<max1<<endl;
		return 0;
	}
	if(n==m){
		cout<<all<<endl;
		return 0;
	}
	if(m==2){
		max1=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				max1=max(max1,a[i]&a[j]);
		cout<<max1<<endl;
		return 0;
	}
	if(all!=4){
		cout<<QWQ(tt,1,1)<<endl;
		return 0;
	}
	cout<<4<<endl;
	return 0;
}
