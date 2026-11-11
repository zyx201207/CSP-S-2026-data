#include<bits/stdc++.h>
using namespace std;

char s[200005], tmp2input[200005];
int n;
bool found=0;
bool lettersShown[27];
int minn=0x3f3f3f3f;
int tmp1input[200005];

bool isHuiwen(char t[], int siz){
    cout << "isHuiwen:" << t << endl;
    for(int i=0;i<siz;i++){
        if(*(t+i)!=*(t+(siz-1-i))){
            return false;
        }
    }
    return true;
}

void dfs(int root, char now[], int level){
    cout << "Root" << root << "Now" << now << "Level" << level << endl;
    if(found) return;
    if(isHuiwen(now,strlen(now))){
        minn = min(minn, level);
        found = 1;
        return;
    }
    char tmp;
    for(int i=1;i<=26;i++){
        if(lettersShown[i]){
            for(int j=root+1;j<strlen(now);j++){
                tmp = now[j];
                now[j] = 'a'+i-1;
                dfs(j+1, now, level+1);
                now[j] = tmp;
            }
        }
    }
}

int gcd(int a, int b){
    if(a==1||b==1) return 1;
    if(b!=0) return gcd(b,a%b);
    return a;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    char tmp;
    int tmp1, slen=0;
    int g=-1;
    for(int i=1;i<=n;i++){
        cin >> tmp1 >> tmp;
        tmp1input[i] = tmp1;
        tmp2input[i] = tmp;
        g = (g==-1?tmp1:gcd(g, tmp1));
    }
    for(int i=1;i<=n;i++){
        for(int j=slen;j<slen+tmp1input[i]/g;j++){
            s[j] = tmp2input[i];
        }
        lettersShown[tmp2input[i]-'a'+1] = 1;
        slen += tmp1input[i]/g;
    }

    dfs(0, s, 0);
    cout << minn*g;
    return 0;
}
