#include<bits/stdc++.h>
using namespace std;
int n;
struct nd{
	int a;
	char b;
};
nd s[100005];
char c[9999999];
int es(int left,int right){
	int sum=0;
	while(right>left){
		if(c[left]!=c[right]){
			sum++;
		}
		left++;
		right--;
	}
	return sum;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>s[i].a>>s[i].b;
	}
	int o=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s[i].a;j++){
			c[o]=s[i].b;
			o++;
		}
	}
    int g=0;
    for(int i=1;i<=n;i++){
    	g+=s[i].a;
	}
	int q=es(1,g);
	cout<<q;
	return 0;
} 
