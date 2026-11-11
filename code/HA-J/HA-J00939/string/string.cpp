#include<bits/stdc++.h>

using namespace std;

int n;
int a[200010];
char ch[200010];

char str1[100000000];
char str2[100000000];

long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		sum+=a[i];
	}
	int len=(sum|1-1)/2;
	
	//cout<<len<<endl;
	
	int l1=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			str1[++l1]=ch[i];
			if(l1==len){
				break;
			}
		}
		if(l1==len){
			break;
		}
	}
	
	/*
	for(int i=1;i<=len;i++){
		cout<<str1[i]<<' ';
	}
	cout<<endl;
	*/
	
	int l2=0;
	for(int i=n;i>=1;i--){
		for(int j=1;j<=a[i];j++){
			str2[++l2]=ch[i];
			if(l2==len){
				break;
			}
		}
		if(l2==len){
			break;
		}
	}
	
	/*
	for(int i=1;i<=len;i++){
		cout<<str2[i]<<' ';
	}
	cout<<endl;
	*/
	
	for(int i=1;i<=len;i++){
		if(str1[i]==str2[i]){
			continue;
		}
		else{
			ans++;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}
