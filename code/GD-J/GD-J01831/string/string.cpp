#include <bits/stdc++.h>
using namespace std;
struct s{
	long long a;
	char c;
	read(){
		cin>>a>>c;
	}
};
s m[200005];
long long w[30];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long len;
	cin>>n;
	for(int i=1;i<=n;i++){
		m[i].read();
		w[m[i].c-'a'+1]+=m[i].a;
		len+=m[i].a;
	}
	int cnt=0;
	for(int i=1;i<=26;i++){
		if(w[i]!=0) cnt++;
	}
	if(cnt==1){
		cout<<"0";
		return 0;
	}
	long long step=0;
	int l=1,r=n;
	while(true){
		if(l>=r) break;
		if(m[l].c==m[r].c)
			if(m[l].a==m[r].a){
				l++;
				r--;
			}
			else {
				step=step+min(m[l].a,m[r].a);
				if(m[l].a>m[r].a){
					m[l].a-=m[r].a;
					r--;
				}
				else{
					m[r].a-=m[l].a;
					l++;
				}
			}
		else
			if(m[l].a==m[r].a){
				step+=m[l].a;
				l++;
				r--;
			}
			else {
				step=step+min(m[l].a,m[r].a);
				if(m[l].a>m[r].a){
					m[l].a-=m[r].a;
					r--;
				}
				else{
					m[r].a-=m[l].a;
					l++;
				}
			}
	}
	cout<<step;
	return 0;
}
