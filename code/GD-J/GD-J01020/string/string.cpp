/*#include<bits/stdc++.h>
using namespace std;
int s;
int a[100005],n,l,l1,r,r1,t;
struct ti{
	int a1;
	int a2;
}at[100005];
char c[100005];
int erfen(int llll){
	int lll=llll;
	l1=1;
	r1=n;
	int ans=-1;
	while(l1<=r1){
		int mid=at[(l1+r1)/2].a1;
		if(mid<l){
			l1=(l1+r1)/2+1;
		}
		if(mid>=l){
			ans=(l1+r1)/2;
			r1=(l1+r1)/2-1;
		}
	}
	int anss=-1;l1=1;
	r1=n;
	while(l1<=r1){
		int mid=at[(l1+r1)/2].a2;
		if(mid<l){
			r1=(l1+r1)/2-1;
		}
		if(mid>=l){
			ans=(l1+r1)/2;
			l1=(l1+r1)/2+1;
		}
	}
	if(c[anss]!=c[ans]){return 1;
	}
	return 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		t+=a[i];
	}
	for(int i=1;i<=n;i++){
		at[i].a1=at[i-1].a1+a[i];
	}
	for(int i=n;i>=1;i--){
		at[i].a2=at[i+1].a2+a[i];
	}
	/*for(int i=1;i<=n;i++){
		cout<<at[i].a1<<" ";
	}
	for(int i=1;i<=n;i++){
		cout<<at[i].a2<<" ";
	}/ *
	while(l+1<t){
		s+=erfen(l++);
	}
	cout<<s/2;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
char c,s[2555565];
int a,n,r,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>s[r];
		r++;
		for(int j=1;j<a;j++){
			s[r]=s[r-1];
			r++;
		}
	}
	for(int i=0;i<r;i++){
		if(s[i]!=s[n-i+1]){t++;
		}
	}
	cout<<t/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
