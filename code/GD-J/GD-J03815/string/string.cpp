#include<iostream>
using namespace std;
string b1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,tmp,total=0,tt=0;
	char c;
	long long a[1000000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp>>c;
		a[i]=tmp;
		b1+=c;
		tt+=tmp;
	}
//	for(int i=n-1;i>=0;i--){
//		for(int j=0;j<a[i][0];j++)bs+=(char)a[i][1]
//	}
	long memout=0;
	for(int i=0,j=n-1;i<=j;i++,j--){
		if(b1[i]!=b1[j]&&a[i]==a[j]&&memout==0)total+=a[i];
		else if(b1[i]==b1[j]&&a[i]!=a[j]&&memout==0){
			if(a[i]>a[j]){
				memout+=a[j]-a[i];
			}if(a[j]>a[i]){
				memout+=a[j]-a[i];
			}
		}
		else if(b1[i]==b1[j]&&memout<0&&j>1&&b1[j-1]==b1[j]){}
		else if(b1[i]==b1[j]&&memout<0&&j>1&&b1[j-1]!=b1[j]){
			total+=abs(memout);
		} 
		else if(b1[i]==b1[j]&&memout>0&&j<n-1&&b1[j+1]==b1[j]){}
		else if(b1[i]==b1[j]&&memout<0&&j<n-1&&b1[j+1]!=b1[j]){
			total+=abs(memout);
		} 
	}
	cout<<total;
}
