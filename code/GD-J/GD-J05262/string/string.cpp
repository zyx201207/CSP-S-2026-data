#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("string.in.txt","r",stdin);
	freopen("string.out.txt","w",stdout);
	int n;
	cin>>n;
	char t[200005];
	int sum=0;
	for(int i=0;i<n;i++){
		int a;
		char l;
		cin>>a>>l;
		for(int j=sum;j<sum+a;j++){
			t[j]=l;
		}
		sum+=a;
	}
	int b=0,e=sum-1;			//aµÄÏÂ±ê 
	int ans=0;
	while(b<=e){
		if(t[b]!=t[e]){
			ans++;
		}
		b++;
		e--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
