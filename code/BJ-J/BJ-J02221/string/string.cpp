#include<bits/stdc++.h>
using namespace std;
string s;
int ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>s;
    int mid;
    if(s.size()%2==0){
    	mid=s.size()/2+1;
    	for(int i=1;i<=mid-1;i++){
    	    if(s[i]!=s[mid+i-1]){
    	    	ans++;
    	    }
    	}
    }
    else{
    	mid=s.size()/2+1;
    	for(int i=1;i<=mid-1;i++){
    	    if(s[i]!=s[mid+i]){
    	    	ans++;
    	    }
    	}
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
