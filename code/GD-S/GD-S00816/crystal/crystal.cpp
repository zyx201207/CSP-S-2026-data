#include<bits/stdc++.h>
using namespace std;
long long m,n,maun=0,num=1,a[1000000],cha[1000000],minn=1000000,minx[1000000];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crestal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);

	long long k=0;
	for(int i=1;i<=n-1;i++){
		cha[i]=a[i+1]-a[i];
		if(cha[i]<=minn){
			minn=cha[i];
		}
	}

	for(int i=1;i<=n-1;i++){
		if(cha[i]==minn){
			k++;
			minx[k]=i;
		}
	}
	
	if(m<minn){
		cout<<1;
		return 0;
	}
	
	int o=1;
	for(int i=1;i<=k;i++){
		while(true){
			if((m-(o*cha[minx[i]+o-1]))>=0&&minx[i]+o-1<n-1){
				m-=o*cha[minx[i]];
				num++;
				o++;
			}
			else{
				break;
			}
		}
		if(num>maun){
			maun=num;
		}
		num=1;o=1;
		while(true){
			int chazong=0;
			chazong+=cha[minx[i]-o+1];
			if((m-chazong)>=0&&minx[i]-o+1>0){
				m-=o*(cha[minx[i]-o+1]);
				num++;
				o++;
			}
			else{
				break;
			}
		}
		if(num>maun){
			maun=num;
		}
		num=1;o=1;
	}
	
	cout<<maun;

}
