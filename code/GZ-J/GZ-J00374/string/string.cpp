//GZ-J00374 兴义市弘毅中学 孙扬
#include<bits/stdc++.h>
using namespace std;

int n,a[100000],sum=0,res=0,smu=0;
string a1[100000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);	
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	getline(cin,a1[i]);
    	sum=sum+a[i];
	}
	for(int i=0,j=0;i<sum/2;i++){
		cout<<a1[i]<<" "<<a1[n-i-1]<<endl;
		if(a1[i]!=a1[n-i]){
			res++;
		}
	}
	cout<<res;
	return 0;
}
/*
2
2 a
3 a
3
2 a
2 b
1 c
*/

