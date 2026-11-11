//GZ-J00573  遵义市第四初级中学  何雨泽 
#include <bits/stdc++.h>
using namespace std;
string ts(int a){
	string s="";
	if(a==0){
		return "Z";
	}
	while(a!=0){
		s=char(a%10+'0')+s;
		a/=10;
	}
	return s;
}
string gjd(string a,string b){
	string u="";
	if(a.size()<b.size()){
		string c=a;
		a=b;
		b=c;
	}
	while(b.size()!=a.size()){
		b="0"+b;
	}
	int aa=a.size()-1;
	int k=0;
	while(aa>=0){
		int s=(a[aa]-'0')+(b[aa]-'0')+k;
		u=ts(s)+u;
		if(u[0]=='Z'){
			u[0]='0';
		}
		aa--;
		k=s/10;
	}
	return u;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s="0";
	int b=0;
	cin>>n;
	int arr[n+1]={};
	char a[n+1]={};
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		b+=arr[i];
		cin>>a[i];
	}
	int l=1;
	int r=n;
	while(l<r){
		if(a[l]!=a[r]){
			if(arr[l]>arr[r]){
				s=gjd(s,ts(arr[r]));
				arr[l]=arr[l]-arr[r];
				r--;
			}
			else if(arr[l]<arr[r]){
				s=gjd(s,ts(arr[l]));
				arr[r]=arr[r]-arr[l];
				l++;
			}
			else{
				s=gjd(s,ts(arr[l]));
				l++;
				r--;
			}
		}
		else{
			if(arr[l]>arr[r]){
				arr[l]=arr[l]-arr[r];
				r--;
			}
			else if(arr[l]<arr[r]){
				arr[r]=arr[r]-arr[l];
				l++;
			}
			else{
				l++;
				r--;
			}
		}
	}
	cout<<s;
	return 0;
}

