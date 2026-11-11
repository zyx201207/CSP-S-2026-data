//GZ-J00651 兴义市弘毅中学  韦杰
#include<bits/stdc++.h>
using namespace std;

int n;
long long ans=0;
string s;

struct st{
	int m;
	char ch;
};
st a[200010];

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].ch;
		for(int j=1;j<=a[i].m;j++){
			s+=a[i].ch;
		}
	}
	
	int head=0;
	int tail=s.length()-1;
	
	while(head<tail){
		if(s[head]!=s[tail]){
			ans++;
		}
		head++;
		tail--;
	}
	cout<<ans;
	return 0;
} 
