#include<bits/stdc++.h>
using namespace std;
string S="A",S1,S2="A";
int A,N;
long long size_S,sum=0,now_size,last_size;
char C,last_c;
struct node{
	long long num;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	size_S+=1;
	cin>>N;
	int n=0;
	while(N--){
		cin>>A>>C;
		S.insert(size_S-1,A,C);
		if(n!=0&&a[n-1].c==C){
			a[--n].num+=A;
		}else{
			a[n].num=A;
			a[n].c==C;
		}n++;
		size_S+=A;
	}
	size_S-=1;
	//cout<<'S'<<S<<endl;
	int flag=1;
	for(int i=0;i<=n/2;i++){
		if(a[i].num!=a[n-i].num||a[i].c!=a[n-i-1].c){
			flag=0;
		}
	}
	if(flag==1){
		cout<<'0';
		return 0;
	}
	for(int i=0;i<size_S/2;i++){
		if(S[i]!=S[size_S-1-i])sum++;
	}
//	size_S/=2;
//	for(int i=0;i<=n/2;i++){
//		now_size+=a[i].num;
//		if(now_size>=size_S){
//			if(a[i].c==last_c)sum=sum+size_S+last_size;
//		}
//	}
	cout<<sum;
	return 0;
}                                 
