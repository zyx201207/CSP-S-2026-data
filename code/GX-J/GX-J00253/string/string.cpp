 #include<bits/stdc++.h>
 using namespace std;
 int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[100005],b[100005],ans=0,sum=0;
	string s[100005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int p=1;p<=a[i];p++){
			s[i]=b[i];
		}
	}
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	for(int i=1;i<=sum;i++){
		for(int p=sum;p>=1;p--){
			if(s[i]!=s[p])ans++;
		}
	}
	cout<<ans;
	return 0;
}
