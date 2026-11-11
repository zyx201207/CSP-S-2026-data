#include<bits/stdc++.h>
using namespace std;
long long n;
string arr;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		char wo;
		cin>>wo;
		for(int i=1;i<=a;i++){
			arr+=wo;
		}
	}
	long long cnt=arr.size();
	if(n==1||n==0){
		cout<<0;
		return 0;
	}
	int flag=1;int i=0,j=cnt-1;
	while(i<j){
		if(arr[i]!=arr[j]){
			flag=0;
		}
		i++;
	}
	if(flag==1){
		cout<<0;
		return 0;
	}
	long long yes=0;
	int q=0,w=(cnt-1)/2,y=(cnt-1)/2,x=cnt-1;
	if(n%2==0){
		while(q<=w&&x>=y){
			if(arr[q]!=arr[x]){
				yes++;
			}
			q++,x--;
		}
		cout<<yes;
	}
	return 0;
}
