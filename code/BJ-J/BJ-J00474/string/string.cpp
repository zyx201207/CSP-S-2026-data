#include<cstdio>
#include<vector>

int main(){
    freopen("string.in","r", stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d", &n);
    std::vector<int> num(n);
    std::vector<char> str(n);
    for(int i = 0; i < n; i++){
        scanf("%d %c\n", &num[i], &str[i]);
    }
    long long str_len = 0;
    for(int i = 0; i < n; i++){
        str_len += num[i];
    }
    std::vector<char> string_full(str_len + 1, 0);
    std::vector<int> nump(n+1,0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            nump[i+1] += num[j];
        }
    }
    int bit = 0;
    for(int i = 0; i < str_len; i++){
        if(nump[bit] <= i && i < nump[bit+1]){
            string_full[i] = str[bit];
        }else{
            bit ++;
            string_full[i] = str[bit];
        }
    }
    //--------------------------------------------ok
    int result = 0;
    for(int i = 0; i < str_len / 2; i++){
        if(string_full[i] != string_full[str_len-i-1]){
            result ++;
        }
        //printf("debug:\n    i:%d b:%c n:%c\n",i,string_full[i],string_full[n-i-1]);
    }
    printf("%d", result);
    return 0;
}