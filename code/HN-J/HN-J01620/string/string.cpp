#include<bits/stdc++.h>
using namespace std;
string a="",f;
bool flag=0;
long long n,m,num=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>m>>f;
		if(m>500){
			flag=1;
		}else{
		while(m>0){
			a+=f;
			m--;
		}
		}
	}
	if(flag==1){
		cout<<0;
		return 0;
	}
	long long len=a.size();
	long long j=len-1;
	for(long long i=0;i<len/2;i++){
		if(a[i]!=a[j]){
			num++;
		}
		j--;
		}
	cout<<num;
	return 0;
}
