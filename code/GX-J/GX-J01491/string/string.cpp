#include<bits/stdc++.h>
using namespace std;
long long a,b=0,w=0;
long long n[100];
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for (int i=0;i<a;i++){
		char c;
		cin>>c;
		int w=int(c);
		cin>>n[w];
		for (int j=0;j<n[w];j++){
			s=s+c;
		}
	}
	b=s.size();
	for (int i=b-1;i>=0;i--){
		s1+=s[i];
	}
	w=a/2;
	if (s1==s) cout<<0;
	else cout<<w;
	return 0;}
//zhe li bu yao kan yin wei mei dong xi
//kan sha kan
//lao bi deng
//ni ma
//gun a
//bie kan le
// ting bu dong ren hua ma
//wo hao lei a
//gun mu gun mu
//xian zai mei shi gan
//ci di wu yin san bai liang
//wo diu lei lao mou
//ylsf zj
// zai jian 
