#include<bits/stdc++.h> 
using namespace std;
char ch[2500005];
long long idx=1,n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int l;
		char number;
		cin>>l>>number;
		for(int j=1;j<=l;j++){
			ch[idx]=number;
			idx++;
		}
	}
	int i=1,j=idx-1;
	while(i<=j){
		if(ch[i]!=ch[j]){
			ans++;
		}
		i++;
		j--;
	}
	cout<<ans;
	return 0;
}
