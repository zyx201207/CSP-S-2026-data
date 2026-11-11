#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int n;
long long a[N];
int Num0_1[N][35];
int weishu[N];
long long ans[35];
bool BXuan[N];
void getNum(long long x,int id){
	long long xx=x;
	int re=0,xb=0;
	int num[35];
	memset(num,0,sizeof num);
	while(xx>0){
		xb++;
		if(xx%2==1){
			re++;
			num[xb]=1;
		}
		xx/=2;
	}
	weishu[id]=xb;
	for(int i=xb,j=1+34-xb;j<=34;j++,i--){
		Num0_1[id][j]=num[i];
	}
}
int m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int minwei=INT_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		getNum(a[i],i);
		if(weishu[i]>minwei){
			minwei=weishu[i];
		}
	}/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=34;j++){
		cout<<Num0_1[i][j];
	}
	cout<<endl;
	}*/
	minwei=34-minwei+1;
	/*
	cout<<minwei<<"MW\n";
	cout<<endl;
	*/
	int BuXuan=0;
	for(int i=minwei;i<=34;i++){
		bool brea=0;
		for(int j=1;j<=n;j++){
			if(Num0_1[j][i]==0){
				BuXuan++;
				//cout<<BuXuan<<"BX"<<j<<endl;
				BXuan[j]=1;
				if(BuXuan==n-m){
					brea=1;
					//cout<<"BREAK!\n";
					break;
				}
			}
		}
		if(brea)break;
	}
	for(int i=minwei;i<=34;i++){
		int weiNum=1;
		for(int j=1;j<=n;j++){
			if(Num0_1[j][i]==0 && BXuan[j]==0){
				weiNum=0;
				break;
			}
		}
		ans[i]=weiNum;
	}
	long long Finans=0;
	/*for(int i=1;i<=34;i++){
		cout<<ans[i];
	}
	cout<<endl;*/
	for(int i=34;i>=1;i--){
		Finans+=ans[i]*(1LL<<((34-i+1)-1));
	}
	cout<<Finans;
	
	return 0;
} 
