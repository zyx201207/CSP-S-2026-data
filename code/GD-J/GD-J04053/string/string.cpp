#include <bits/stdc++.h>
using namespace std;

struct num{
	int a;
	char c;
	
}s[200100];

int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int n;
	long long t=0,res=0,l=0,mid=0;
	cin >> n;
	int k=n;
	for (int i=1;i<=n;i++){
		cin >> s[i].a >> s[i].c;
		t+=s[i].a;
	} 


	int i=1;
	mid=t/2;
	while (i<k){
		
        
		if (s[i].a >= s[k].a){
			//cout << s[i].a << " " << s[k].a << endl;	
			s[i].a-=s[k].a;
			l+=s[k].a;
			if (s[i].c != s[k].c) res+=s[k].a;
			k--;
		
		}
	
		else{
			//cout << s[i].a << " " << s[k].a << endl;
			s[k].a-=s[i].a;
			l+=s[i].a;
			
			if (s[i].c != s[k].c) res+=s[i].a;
			i++;
			

		}
			
	}
	
	
	cout << res;
	return 0;
} 
