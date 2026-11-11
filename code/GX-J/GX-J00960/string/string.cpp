//not all AC
//I have no better idea
#include<cstdio>
#include<string>
using namespace std;
string s,s1;
int n,a;
char c,d;
unsigned long long sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%c%c",&a,&d,&c);//<-Because a space there
        for(int i=0;i<a;i++,s+=c);
    }
    for(unsigned long long i=0,j=s.size()-1;i<=j;i++,j--){
        if(s[i]!=s[j])sum++;//<-it look like a bad idea
    }
    printf("%llu",sum);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
CCF,who teach you make date like this?
that's bad!!!
:(
XYO!
*/
