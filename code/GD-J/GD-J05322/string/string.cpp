#include <bits/stdc++.h>
using namespace std;

struct node{
	long long a;
	char c;
}str[200005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n;
	cin>>n;
	
	for (int i=1;i<=n;i++){
		cin>>str[i].a>>str[i].c;
	}
	
	long long cnt=0;
	
	int i=1,j=n;
	while (i<=j){
		if (str[i].c!=str[j].c){
			if (str[i].a<str[j].a){
				str[j].a-=str[i].a;
				cnt+=str[i].a;
				i++;
			}else{
				str[i].a-=str[j].a;
				cnt+=str[j].a;
				j--;
			}
		}else {
			if (str[i].c!=str[j].c)
				str[j].a-=str[i].a;
			else 
				str[i].a-=str[j].a;
			i++;
			j--;
		}
	}
	
	cout<<cnt;
	
	return 0;
}
