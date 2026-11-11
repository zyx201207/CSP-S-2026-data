#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,ms=0,max=0;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]>a[i+1]){
			max=a[i];
			a[i]=a[i+1];
			a[i+1]=max;
		}
	}	
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			ms++;
			if(a[i+2]==a[i+1]){
				ms++;
				if(a[i+2]==a[i+3]){
				ms++;
				if(a[i+4]==a[i+3]){
				ms++;
			}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if((a[i]+a[i+1]+m)/2==a[i+2]){
			cout<<ms+3;
			break;
		}else if((a[i]+a[i+1]+a[i+2]+m)/3==a[i+3]){
			cout<<ms+4;
			break;
		}else if((a[i]+a[i+1]+a[i+2]+a[i+3]+m)/4==a[i+4]){
			cout<<ms+5;
			break;
		}else if((a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+m)/5==a[i+5]){
			cout<<ms+6;
			break;
		}else if((a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+m)/6==a[i+6]){
			cout<<ms+7;
			break;
		}else if((a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+m)/7==a[i+7]){
			cout<<ms+8;
			break;
		}else if((a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]+m)/8==a[i+8]){
			cout<<ms+9;
			break;
		}else if((a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]+a[i+8]+m)/9==a[i+9]){
			cout<<ms+10;
			break;
		}
	}

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
}
