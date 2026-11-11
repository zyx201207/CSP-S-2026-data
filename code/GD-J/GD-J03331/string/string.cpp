#include<bits/stdc++.h>
using namespace std;
long long n;
long long cut;
string a="";
//void sum(int m,char q){
//	if(m==0)return;
//	a+=q;
//	sum(m-1,q);
//}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>n;
	int m;
	char q;
	for(int i=0;i<n;++i){
		cin>>m>>q;
		for(int i=0;i<m;++i)a=a+q;
	}//

	int len=a.size()-1;
	for(int i=0;i<=len/2;++i)
		if(a[i]!=a[len-i])
			cut+=1;
	cout<<cut;
    return 0;
}
//6 
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b


//4
//3 a
//3 b
//3 c
//3 a
