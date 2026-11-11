#include<bits/stdc++.h> 
using namespace std;
struct z{
	int nm;
	char x;
}l[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
int n;
cin>>n;
char b[200001];
int a[200001];
int asd=0;

for(int i=1;i<=n;i++){
cin>>l[i].nm>>l[i].x;
}
for(int i=1;i<=n;i++){
	b[i]+=l[i].x;
}
int j=1;
char b1[200001];
for(int i=n;i>=1;i--){
	b1[j++]+=l[i].x;
}


for(int i=1;i<=n;i++){
	if(b[i]!=b1[i]){
		asd++;
	}
}
cout<<asd;
	return 0;
}


