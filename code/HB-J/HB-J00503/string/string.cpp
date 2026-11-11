#include<bits/stdc++.h>
using namespace std;
int f1,adr,h,t,n;
unsigned long long sum,sun,s,num[200007];
char a[200007];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>a[i];
		sum+=num[i];
		if(i!=1&&a[i]!=a[i-1]) f1=1;
	}
	h=1,t=n;
	if(f1==0||n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(num[1]==num[2]) cout<<num[1];
		else cout<<min(num[1],num[2]);
		return 0;
	}
	sun=sum/2;
	for(int i=1;i<=n;i++){
		if(sun<=num[i]){
			adr=i;
			break;
		}
		sun-=num[i];
	}
	while(1){
		if(h>=t) break;
		if(a[h]!=a[t]) s+=min(num[h],num[t]);
		if(num[h]==num[t]){
			h++;
			t--;
		}
		else if(num[h]>num[t]){
			num[h]-=num[t];
			t--;
		}
		else{
			num[t]-=num[h];
			h++;
		}
	}
	cout<<s;
	return 0;
}
