#include <bits/stdc++.h>
using namespace std;
long long a;
const long long N=2*1e6;
char c;
int s1[N];
char hh[N];
string ans_1,ans_2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string1.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin >> n;
	int beg=0;
	int nn=0;
	int ll=0;
	char lastt;
	for(int i=1;i<=n;i++){
		cin >> a >> c;
		nn+=a;
		s1[beg]+=c-'a';
		s1[beg+a]-=c-'a';
		beg+=a;
		if(i==1){
			lastt=c;
			ll+=a;
			continue;
		}
		if(c==lastt){
			ll+=a;
		}
		else lastt=0+'0';
	}
	if(nn==3||ll==nn){
		cout << 0;
		return 0;
	}
	string s_1;
	for(int i=0,j=nn-1;i<nn;i++,j--){
		s1[i]+=s1[i-1];
		s_1+=s1[i]+'a';
		hh[j]=s1[i]+'a';
	} 
	for(int i=0,j=nn-1;i<nn;i++,j--){
		bool f=0;
		for(int k=i+1;k<j;k++){
			ans_1=s_1[k];
			ans_2=hh[k];
			f=1;
		}
		if(f==0){
			cout << i+1;
		}
		if(ans_1==ans_2){
			cout << i+1;
			return 0;
		}
	}
	return 0;
} 
