#include<bits/stdc++.h>
using namespace std;
int n,m,arr1[200010],arr2[200010],ind2;
int main(){
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>arr1[i];
	}
	int max1=-1;
	bool c;
	int num;
	if(m==1){
		for(int i = 1;i<=n;i++){
			max1=max(max1,arr1[i]);
		}
		cout<<max1;
	}
	else{
		if(m==n){
			for(int i = 1;i<=n;i++){
				c=1,num=arr1[1];
				for(int j = 2;j<=n;j++){
					if(arr1[j]%2!=num%2) c=0;
				}
				if(c==1) arr2[++ind2]=1;
				else arr2[++ind2]=0;
				for(int j = 1;j<=n;j++){
					arr1[j]/=2;
				}
			}
			int k = 0,num=0;
			for(int i = 1;i<=n;i++){
				if(arr2[1]==0) continue;
				num+=pow(arr2[i],pow(2,k));
				k++;
			}
			cout<<num;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}

