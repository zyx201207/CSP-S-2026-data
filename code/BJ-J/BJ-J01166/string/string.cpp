#include<bits/stdc++.h>
using namespace std;
int a,n;
char x;
string s;
void abc(int a,int x){
	for(int i=1;i<=a;i++){
		s+=x;
	}
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
  for(int i=1;i<=n;i++){
	  cin>>a>>x;
	  abc(a,x);
  }
	long long len=s.size(),biao=len-1,ans=0;
	for(int i=0;i<len;i++){
		if(s[i]==s[biao]){
			biao--;
			continue;
		}else{
			ans++;
		}
		biao--;
	}
	cout<<ans/2;
	
    return 0;
}
