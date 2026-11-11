#include<cstdio>
#include<iostream>

using namespace std;

int n,t = 0;
struct A{
	int a;
	char c;
}note[200000 + 10];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++ i){
		cin >> note[i].a >> note[i].c;
	}
	
	for(int i = 0 ; i < n/2 ; ++ i){
		if(note[i].a > note[n - i].a){
			if(note[i].c != note[n - i].c) t += note[n - i].a;
			if(note[i].c != note[n - i - 1].c)t += note[i].a - note[n - i].a;
			note[n - i - 1].a -= note[i].a - note[n - i].a;
		}
		if(note[i].a < note[n - i].a){
			if(note[i].c != note[n - i].c) t += note[i].a;
			if(note[n - i].c != note[i + 1].c)t += note[n - i].a - note[i].a;
			note[i + 1].a -= note[n - i].a - note[i].a;
		}
		if(note[i].a == note[n - i].a){
			if(note[i].c != note[n - i].c) t += note[i].a;
		}
	}
	
	printf("%d",t);
	
	return 0;
}
