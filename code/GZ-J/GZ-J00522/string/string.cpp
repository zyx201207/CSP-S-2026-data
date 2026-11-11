//GZ-J00522 贵州省兴义市弘毅中学 骆奇凡
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	long long n,m,cnt=0,q,k;
	char a;
	string l;
	cin>>n;
	while(n--){
		cin>>m;
		cin>>a;
		for(int i=0;i<m;i++)l+=a;
		k+=m;
	}
	if(k%2==0){
	q=k/2;
	}else{q=k/2+1;
	}
	for(int i=0;i<q;i++){
		if(l[i]==l[k-i-1])cnt++;
	}
	cout<<q-cnt;
	return 0;
}
