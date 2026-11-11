#include<bits/stdc++.h>
using namespace std;
string str,ts;
long long n,dfce;//dfce由difference(n.不同)简化而来
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		string c;
		cin>>a>>c;
		while(a--){
			str=str+c;
		}
	}
	if(str.size()%2!=0){
		for(int i=str.size()-1;i>=str.size()/2;i--) ts+=str[i];
	}    
	else{
		for(int i=str.size()-1;i>=str.size()/2;i--) ts+=str[i];
	}
	for(int i=0;i<ts.size();i++){
		if(str[i]!=ts[i]) dfce++;
	}
	cout<<dfce<<endl;
	return 0;
}
//这题我不太好理解，我想到的办法就是字符串拆一半比较，看看多少不同