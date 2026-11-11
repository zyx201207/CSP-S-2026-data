#include<bits/stdc++.h>
using namespace std;
int n;
struct st{
	int a;
	char b;
}c[200005];
long long s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i].a>>c[i].b;
	for(int i=1,j=n;;){
		if(c[i].b!=c[j].b) s+=min(c[i].a,c[j].a);
		if(c[i].a<c[j].a){
			c[j].a-=c[i].a;
			i++;
		}
		else if(c[i].a>c[j].a){
			c[i].a-=c[j].a;
			j--;
		}
		else{
			i++;
			j--;
		} 
		if(i>=j) break;
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

