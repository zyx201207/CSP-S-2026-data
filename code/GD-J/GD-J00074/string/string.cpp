#include<bits/stdc++.h>
using namespace std;
string b(100000000,'0'); 
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int count=0;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		char c;
		cin>>c;
		for(int j=count;j<a+count;j++){
			b[j]=c;
		}
		count+=a;
	}
	//cout<<b<<endl<<endl;
	int count1=0;
	for(int j=0;j<count/2;j++){
		//cout<<b[j]<<b[count-j-1];
		if(b[j]!=b[count-1-j]) 
		{
			//cout<<b[j]<<' '<<b[count-j-1]<<endl;
		count1+=1;
		}
	}
	cout<<count1;
	//cout<<b;
}
