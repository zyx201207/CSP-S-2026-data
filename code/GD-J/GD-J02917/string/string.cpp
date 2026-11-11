#include<bits/stdc++.h>
using namespace std;
#define Freopen(x) _Freopen(#x)
void _Freopen(string file){
	freopen((file+".in").c_str(),"r",stdin);
	freopen((file+".out").c_str(),"w",stdout);
}
void Fclose(){
	fclose(stdin);
	fclose(stdout);
}
int n,a;
long long ans;
char c;
string s,t;
int main(int argc,char** argv){
//	Freopen(and);
//	Freopen(card);
	Freopen(string);
//	Freopen(travel);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		s+=string(a,c);
	}
	t=s;
	reverse(t.begin(),t.end());
	for(int i=0;i<s.size();i++){
		if(s[i]!=t[i])ans++;
	} 
	cout<<ans/2;
//	for(int i=1;i<=n;i++){
//		cin>>a[x]>>c[x];
//		if(c[x]==c[x-1]){
//			a[x-1]+=a[x];
//		}else{
//			x++;
//		}
//	} 
//	for(int i=1,j=x;i<=x&&j>=1;){
//		if(i==j)break;
//		if(a[i]==a[j]&&c[i]==c[j])i++,j--;
//		if(a[i]==a[j]&&c[i]!=c[j])ans+=a[i],i++,j--;
//		if(a[i]>a[j]){
//			int x=a[i];
//			if(c[i]!=c[j]){
//				ans+=a[i]-a[j];
//				x-=a[i]-a[j];
//			}
//			j--;
//			while(j>=1){
//				if(c[i]!=c[j]){
//					if(x==a[j]){
//						ans+=c[j];
//						break;
//					}else if(x<a[j]){
//						
//					}
//				}
//			} 
//		}
//	}
	Fclose();
	return EXIT_SUCCESS; 
}
