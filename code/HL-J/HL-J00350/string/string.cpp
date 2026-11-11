#include <iostream>
using namespace std;
string s;
void ans(int a,char c){
	string q;
	for(int i=1;i<=a;i++){
		q+=c;
	}
	s+=q;
	return;
}
//
//
//
//
//			0	1   2 	3  	4 	5
//						cnt
//			i	
//								j	
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,t;
	unsigned long long u=0;
	char c;
	int a;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		cnt+=a;
		ans(a,c);
	}
	if(cnt%2!=0){
		t=cnt;
		cnt=(cnt-1)/2;
		for(int i=0,j=cnt+1;i<cnt,j<t;i++,j++){
			if(s[i]!=s[j]){
				u++;
			}
		}
	}else{
		t=cnt;
		cnt/=2;
		for(int i=0,j=cnt;i<cnt,j<t;i++,j++){
			if(s[i]!=s[j]){
				u++;
			}
		}
	}
	cout<<u;
	return 0;
}
