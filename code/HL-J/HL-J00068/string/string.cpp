#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
char ch[200010];
long long s[200010];
long long ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		s[i]=s[i-1]+a[i];
	}
	long long idi=1,posi=1,idj=n,posj=s[n];
	while(posi<posj){
		if(ch[idi]!=ch[idj]) ans+=min(s[idi]-posi+1,posj-s[idj-1]);
		if(s[idi]-posi+1<=posj-s[idj-1]){
			posj-=(s[idi]-posi+1);
			idi++;
			posi=s[idi-1]+1;
		}
		else{
			posi+=(posj-s[idj-1]);
			idj--;
			posj=s[idj];
		}
	}
	cout<<ans<<"\n";
	return 0;
}

/*
2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/