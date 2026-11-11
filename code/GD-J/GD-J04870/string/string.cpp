#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
	long long a;
	char c;
}s[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	int l=1,r=n;
	while(r>l){
		long long minn=min(s[l].a,s[r].a);
		if(s[l].c==s[r].c){
			s[l].a-=minn;
			s[r].a-=minn;
			if(s[l].a==0)l++;
			if(s[r].a==0)r--;
		}else{
			ans+=minn;
			s[l].a-=minn;
			s[r].a-=minn;
			if(s[l].a==0)l++;
			if(s[r].a==0)r--;
		}
	}
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
