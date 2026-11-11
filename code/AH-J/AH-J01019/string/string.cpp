#include<bits/stdc++.h>
using namespace std;

int _;

int n;

long long L;

struct node{
	long long times;
	char c;
}arr[512345];

long long x;

string op;

char tht;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>_;
	n=L=0;
	while(_--){
		cin>>x>>op;
		L+=x;
		tht=op[0];
		if(n==0){
			arr[n]={x,tht};
			n++;
			continue;
		}
		if(arr[n-1].c==tht){
			arr[n-1].times+=x;
			continue;
		}
		arr[n]={x,tht};
		n++;
	}
	if(L%2){
		long long now=0;
		int broken=-1;
		for(int i=0;i<n;i++){
			now+=arr[i].times;
			if(now>=(L/2)+1){
				n++;
				for(int j=n-1;j>i;j--){
					arr[j]=arr[j-1];
				}
				arr[i+1].times=(now-L/2-1);
				arr[i].times-=(now-L/2);
				broken=i+1;
				break;
			}
		}
		int j=broken;
		int i=broken-1;
		long long ans=0;
		while(0<=i&&j<n){
			if(arr[i].c==arr[j].c){
				if(arr[i].times>arr[j].times){
					arr[i].times-=arr[j].times;
					j++;
				}else if(arr[i].times<arr[j].times){
					arr[j].times-=arr[i].times;
					i--;
				}else{
					j++;
					i--;
				}
				continue;
			}
			ans+=min(arr[i].times,arr[j].times);
			if(arr[i].times>arr[j].times){
				arr[i].times-=arr[j].times;
				j++;
			}else if(arr[i].times<arr[j].times){
				arr[j].times-=arr[i].times;
				i--;
			}else{
				j++;
				i--;
			}
		}
		cout<<ans;
		return 0;
	}
	long long now=0;
	int broken=-1;
	for(int i=0;i<n;i++){
		now+=arr[i].times;
		if(now>(L/2)){
			n++;
			for(int j=n-1;j>i;j--){
				arr[j]=arr[j-1];
			}
			arr[i+1].times=(now-L/2);
			arr[i].times-=(now-L/2);
			broken=i+1;
			break;
		}
	}
	int j=broken;
	int i=broken-1;
	long long ans=0;
	while(0<=i&&j<n){
		if(arr[i].c==arr[j].c){
			if(arr[i].times>arr[j].times){
				arr[i].times-=arr[j].times;
				j++;
			}else if(arr[i].times<arr[j].times){
				arr[j].times-=arr[i].times;
				i--;
			}else{
				j++;
				i--;
			}
			continue;
		}
		ans+=min(arr[i].times,arr[j].times);
		if(arr[i].times>arr[j].times){
			arr[i].times-=arr[j].times;
			j++;
		}else if(arr[i].times<arr[j].times){
			arr[j].times-=arr[i].times;
			i--;
		}else{
			j++;
			i--;
		}
	}
	cout<<ans;
	return 0;
}
